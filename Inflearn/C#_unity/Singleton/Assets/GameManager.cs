using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour {
    public Text scoreText;
    public int Score    // 프로퍼티
    {
        get
        {
            return score;
        }
        set
        {
            score = value;
            scoreText.text = value.ToString("N0");
        }
    }
    private int score;

    public static GameManager instance;  // 싱클톤 생성
    void Awake()
    {
        if (instance)
        {
            Destroy(gameObject);
            return;
        }
        instance = this;
    }


}
