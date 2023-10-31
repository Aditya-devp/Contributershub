//* https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=disjoint-set-union-find
//* https://youtu.be/aBxjDBC4M1U

/*Complete the functions below*/
int find(int A[],int X)
{
    //add code here
    
    if(A[X] == X){
        return X;
    }

    return A[X] = find(A, A[X]); // path compression
}

void unionSet(int A[],int X,int Z)
{
	//add code here.
	
	int ulp_x = find(A, X);
	int ulp_z = find(A, Z);
	
	// if ultimate parents are same, no change required
	if(ulp_x == ulp_z){
        return;
	}
	
	A[ulp_x] = ulp_z; // union
}