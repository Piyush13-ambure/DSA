/*Given a set of coordinates points of the form [p, q] and a line L of the form ax + by + c = 0. The task is to find a point on a given line for which the sum of distances from a given set of coordinates is minimum
Your Task:  
You don't need to read input or print anything. Your task is to complete the function findOptimumCost() which takes a line L and coordinates and returns an double up to 2 decimal places as output
*/

#define sq(x) ((x) * (x))
#define EPS 1e-6

class Solution{
    public:
    double dist(double x, double y, pair<int,int>p){
	    return sqrt(sq(x - p.first) + sq(y - p.second));
    }
    double compute(vector<pair<int,int>>p, int n, tuple<int,int,int>l, double X){
	    double res = 0;

	    // calculating Y of chosen point by line equation
	    double Y = -1 * (get<2>(l) + get<0>(l) * X) /get<1>(l);
	    for (int i = 0; i < n; i++){
		    res += dist(X, Y, p[i]);
	    }
	    return res;
    }

    // Utility method to find minimum total distance
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    double low = -1e6;
	    double high = 1e6;

	    // loop until difference between low and high
	    // become less than EPS
	    while ((high - low) > EPS) {
		    // mid1 and mid2 are representative x co-ordiantes
		    // of search space
		    double mid1 = low + (high - low) / 3;
		    double mid2 = high - (high - low) / 3;


	    	double dist1 = compute(p, n, l, mid1);
		    double dist2 = compute(p, n, l, mid2);

		    // if mid2 point gives more total distance,
		    // skip third part
		    if (dist1 < dist2)
			    high = mid2;

		    // if mid1 point gives more total distance,
		    // skip first part
		    else
			    low = mid1;
	    }

	    // compute optimum distance cost by sending average
	    // of low and high as X
	    return compute(p, n, l, (low + high) / 2);
    }
};
