class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bottom=matrix.size()-1;
        int top=0, left=0;
        while(top<=bottom)
        {
            int mid=top+(bottom-top)/2;
            if(matrix[mid][0]>target)
                bottom=mid-1;
            if(matrix[mid][matrix[0].size()-1]<target)
                top=mid+1;
            if(target>=matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1])
            {
                 int left=0, right=matrix[0].size()-1;
                 while(left<=right)
                 {
                    int m=left+(right-left)/2;
                    if(matrix[mid][m]<target)
                       left=m+1;
                    if(matrix[mid][m]>target)
                        right=m-1;
                    if(matrix[mid][m]==target)
                        return true;
                 }
                 return false;
            }

        }
        return false;
    }
};