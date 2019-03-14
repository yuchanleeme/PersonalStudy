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

    private static GameManager instance;  // private 싱클톤 생성
    public static GameManager Instance    // public 으로 Instance를 만들어 다른 곳에서
    {                                     // instance값을 못 바꾸게 한다.
        get {return instance; }  
    }

    void Awake()
    {
        if (instance)
        {
            Destroy(gameObject);
            return;
        }
        instance = this;

        DontDestroyOnLoad(instance); // 다른 씬에서도 사용할 경우
    }


}
