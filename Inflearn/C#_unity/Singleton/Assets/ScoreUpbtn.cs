using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreUpbtn : MonoBehaviour {
    public GameManager GM; // gameManager 객체 선언후 그 객체 값 증가
    public void upScore()
    {
        GM.Score += 100;
    }

	
}
