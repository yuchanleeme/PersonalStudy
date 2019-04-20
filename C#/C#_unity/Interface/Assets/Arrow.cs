using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Arrow : MonoBehaviour {


	// Update is called once per frame
	void Update () { 
        GetComponent<Rigidbody2D>().AddForce(Vector3.right * 10f); // arrow 에 addforce
    }
    private void OnCollisionExit2D(Collision2D collision) // 충돌값이 끝나는 순간까지만 pool 사용
    {
        GetComponent<PoolableObject>().Push();
    }
}
