
    class Solution {
public:
   double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, int>> q;
    int n = classes.size();

    // Calculate the initial ratios and their improvements
    for (int i = 0; i < classes.size(); i++) {
        int p = classes[i][0];  // Passed students
        int t = classes[i][1];  // Total students
        double ratio = (double)p / (double)t;
        // Calculate the improvement of adding one student
        double improvement = ((double)(p + 1) / (double)(t + 1)) - ratio;
        q.push({improvement, i});  // Push the change and class index to the heap
    }

    // Add extra students to the classes with the maximum change in ratio
    while (extraStudents > 0) {
        pair<double, int> top = q.top();  // Get the class with the max improvement
        q.pop();
        
        int ind = top.second;
        classes[ind][0]++;  // Add one passed student
        classes[ind][1]++;  // Add one total student

        // Recalculate the new improvement and push it back to the heap
        int p = classes[ind][0];
        int t = classes[ind][1];
        double newRatio = (double)p / (double)t;
        double improvement = ((double)(p + 1) / (double)(t + 1)) - newRatio;
        q.push({improvement, ind});
        
        extraStudents--;  // Decrease the number of extra students
    }

    // Calculate the final average pass ratio
    double ans = 0;
    for (int i = 0; i < classes.size(); i++) {
        ans += (double)classes[i][0] / (double)classes[i][1];
    }
    
    return ans / (double)n;
}
};