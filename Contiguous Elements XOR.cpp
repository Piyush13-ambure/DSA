/*You are given an array arr[] of N positive integers. This time you are supposed to choose numbers from a contiguous sub-sequence of the given array, so that BITWISE XOR of all the chosen numbers is maximum.*/


// A Trie Node 
struct TrieNode 
{ 
	int value; // Only used in leaf nodes 
	TrieNode *arr[2]; 
}; 

// Utility function to create a Trie node 
TrieNode *newNode(){
  
  TrieNode *temp = new TrieNode;
  temp->value = 0;
  temp->arr[0] = temp->arr[1] = NULL;
  return temp;

}


//Function to insert pre_xor to trie with given root. 
void insert(TrieNode *root, int pre_xor) 
{ 
	TrieNode *temp = root; 

	//starting from the msb and inserting all bits of pre_xor into Trie. 
	for (int i=INT_SIZE-1; i>=0; i--) 
	{ 
		//finding current bit in given prefix. 
		bool val = pre_xor & (1<<i); 

		//creating a new node if needed. 
		if (temp->arr[val] == NULL) 
			temp->arr[val] = newNode(); 

		temp = temp->arr[val]; 
	} 
    //storing value at leaf node.
	temp->value = pre_xor; 
} 


//Function to find the maximum XOR ending with last number in 
//prefix XOR 'pre_xor'  and return the XOR of this maximum ith pre_xor 
//which is maximum XOR ending with last element of pre_xor.
int query(TrieNode *root, int pre_xor) 
{ 
	TrieNode *temp = root; 
	for (int i=INT_SIZE-1; i>=0; i--) 
	{ 
		//finding current bit in given prefix. 
		bool val = pre_xor & (1<<i); 

		//traverse Trie and looking for a prefix that has opposite bit,
		if (temp->arr[1-val]!=NULL) 
			temp = temp->arr[1-val]; 

		//if there is no prefix with opposite bit then looking for same bit. 
		else if (temp->arr[val] != NULL) 
			temp = temp->arr[val]; 
	} 
	return pre_xor^(temp->value); 
} 


class Solution
{
    public:
    //Function to return maximum XOR value. 
    int maxSubarrayXOR(int arr[], int n) 
    { 
    	//creating a Trie and inserting 0 into it. 
    	TrieNode *root = newNode(); 
    	insert(root, 0); 
    
    	//initializing answer and xor of current prefix.
    	int result = INT_MIN, pre_xor =0; 
    
    	//traversing all input array elements. 
    	for (int i=0; i<n; i++) 
    	{ 
    		//updating current prefix xor and inserting it into Trie .
    		pre_xor = pre_xor^arr[i]; 
    		insert(root, pre_xor); 
    
    		//Query for current prefix xor in Trie and updating 
    		//result if required.
    		result = max(result, query(root, pre_xor)); 
    	} 
    	return result; 
    } 
};
