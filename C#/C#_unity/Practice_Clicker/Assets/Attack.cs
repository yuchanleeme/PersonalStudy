using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Attack : MonoBehaviour {
    int score = 0;
    Text scoreText;
	// Use this for initialization
	public void ScoreUp(int number)
    {
        score += number;
        GetComponent<Text>().text = "Score :"+score;
    }
}
