using UnityEngine;
using UnityEngine.SceneManagement;

namespace LemonLoader.Support
{
    internal static class Main
    {
        internal static bool IsDestroying = false;
        internal static GameObject obj = null;
        internal static LemonLoaderComponent comp = null;
        private static ISupportModule Initialize()
        {
            LemonLoaderComponent.Create();
            SceneManager.sceneLoaded += OnSceneLoad;
            return new Module();
        }
        private static void OnSceneLoad(Scene scene, LoadSceneMode mode) { if (!scene.Equals(null)) SceneHandler.OnSceneLoad(scene.buildIndex); }
    }
    public class LemonLoaderComponent : MonoBehaviour
    {
        internal static void Create()
        {
            Main.obj = new GameObject("LemonLoader");
            DontDestroyOnLoad(Main.obj);
            Main.comp = Main.obj.AddComponent<LemonLoaderComponent>();
            Main.obj.transform.SetAsLastSibling();
            Main.comp.transform.SetAsLastSibling();
        }
        internal static void Destroy() { Main.IsDestroying = true; if (Main.obj != null) GameObject.Destroy(Main.obj); }
        void Start() => transform.SetAsLastSibling();
        void Update() { transform.SetAsLastSibling(); LemonLoader.Main.OnUpdate(); }
        void FixedUpdate() => LemonLoader.Main.OnFixedUpdate();
        void LateUpdate() => LemonLoader.Main.OnLateUpdate();
        void OnGUI() => LemonLoader.Main.OnGUI();
        void OnDestroy() { if (!Main.IsDestroying) Create(); }
        void OnApplicationQuit() { Destroy(); LemonLoader.Main.OnApplicationQuit(); }
    }
}