using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Box : MonoBehaviour {

    public GameObject arrowObj;
    public Transform shootPosTf;
    public KeyCode shootKey;


    public void Update()
    {
        if (Input.GetKeyDown(shootKey))
        {
            Instantiate(arrowObj, shootPosTf.position, Quaternion.identity);
        }
    }
}
