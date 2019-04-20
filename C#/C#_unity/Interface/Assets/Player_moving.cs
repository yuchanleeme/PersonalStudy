using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_moving : MonoBehaviour {
    public GameObject player_obj;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        // 게임 오브젝트 활성화 / 비활성화
        if (Input.GetKeyDown(KeyCode.LeftArrow))
        {
            player_obj.SetActive(false);
        }
        if (Input.GetKeyDown(KeyCode.RightArrow))
        {
            player_obj.SetActive(true);
        }


    }
}
