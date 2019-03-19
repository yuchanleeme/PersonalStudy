using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Arrow : MonoBehaviour {


	// Update is called once per frame
	void Update () { 
        GetComponent<Rigidbody2D>().AddForce(Vector3.right * 10f); // arrow 에 addforce
    }
}
