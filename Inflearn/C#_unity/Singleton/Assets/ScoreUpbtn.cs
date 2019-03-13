using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreUpbtn : MonoBehaviour {
    public void upScore()
    {
        GameManager.instance.Score += 100; // 싱글톤 인스턴스 선언으로 코드 줄임
    }

	
}
