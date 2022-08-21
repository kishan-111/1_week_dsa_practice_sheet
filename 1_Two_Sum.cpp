Given an array A and an integer target, find the indices of the two numbers in the array whose sum is equal to the given target.

Note: The problem has exactly one solution. Do not use the same element twice.

Example
A: [1, 3, 3, 4]
target: 5
Answer: [0, 3]
Testing
Input Format
The first line contains an integer ‘T’ denoting the number of test cases.

For each test case, the input has three lines:

An integer ’n’ denoting the length of the array.
n space-separated integers denoting the elements of the array.
An integer ‘target’ denoting the target value.
Output Format
For each test case, the output has two space-separated integers ‘i’ and ‘j’ denoting the indices of the array.

Sample Input
2
6
8 2 10 4 1 3
9
5
2 4 2 3 2
7
Expected Output
0 4
1 3
Constraints
1 <= T <= 10
2 <= n <= 105
-109 <= Ai <= 109
-109 <= target <= 109

Approach 1:
pair<int,int> twoSum(vector<int> &a, int target) {
   int n=a.size();
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(a[i]+a[j]==target){
        return {i,j};
      }
    }
  }
  return {-1,-1};
}
Time Complexity: O(n^2)
Space complexity: O(1)
  
Approach 2:
pair<int,int> twoSum(vector<int> &a, int target) {
	vector<pair<int,int>> v;
  int n=a.size();
  for(int i=0;i<n;i++){
    v.push_back({a[i],i});
  }
  sort(v.begin(),v.end());
  int left=0;
  int right=n-1;
  while(left<right){
    if(a[left].first+a[right].first==target){
      return {a[left].second,a[right].second};
    }else if(a[left].first+a[right].first>target){
      right--;
    }else{
      left++;
    }
  }
  return {-1,-1};
}
Time Complexity: O(nlogn)
Space complexity: O(n)  

Approach 3:
pair<int,int> twoSum(vector<int> &a, int target) {
	map<int,int> m;
	for(int i=0;i<a.size();i++){
		if(m.find(target-a[i])!=m.end()){
			return {i,m[target-a[i]]};
		}
		m[a[i]]=i;
	}
	return {-1,-1};
}
Time Complexity: O(n)
Space complexity: O(n)
