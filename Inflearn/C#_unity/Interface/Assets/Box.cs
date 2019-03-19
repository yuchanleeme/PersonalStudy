using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Box : MonoBehaviour {

    public GameObject arrowObj;
    public Transform shootPosTf;
    public KeyCode shootKey;


    void Update()
    {
        if (Input.GetKeyDown(shootKey))
        {
            Instantiate(arrowObj).transform.position = shootPosTf.position; // 회전 유지
            //Instantiate(arrowObj, shootPosTf.position, Quaternion.identity); // 회전 없음
        }
    }
}
