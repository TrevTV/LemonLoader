using System.Collections;
using UnityEngine;

namespace LemonLoader.Support
{
    public class Module : ISupportModule
    {
        public string GetUnityVersion() => Application.unityVersion;
        public float GetUnityDeltaTime() => Time.deltaTime;
        public int GetActiveSceneIndex() => Main.CurrentScene;
        public object StartCoroutine(IEnumerator coroutine) => Main.comp.StartCoroutine(coroutine);
        public void StopCoroutine(object coroutineToken) => Main.comp.StopCoroutine((Coroutine) coroutineToken);
        public void UnityDebugLog(string msg) => Debug.Log(msg);
        public void Destroy() => LemonLoaderComponent.Destroy();
    }
}