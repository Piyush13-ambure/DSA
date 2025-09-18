/*There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.

Implement the TaskManager class:

TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the given priority.

void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to the user with userId. It is guaranteed that taskId does not exist in the system.

void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. It is guaranteed that taskId exists in the system.

void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that taskId exists in the system.

int execTop() executes the task with the highest priority across all users. If there are multiple tasks with the same highest priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the userId associated with the executed task. If no tasks are available, return -1.

Note that a user may be assigned multiple tasks.

*/

// modified C-array version
using int2=pair<int , int>; 
int2 mp[100001];// taskID->(prioity, userId)
class TaskManager {
    int maxI=-1;
    priority_queue<int2> pq; //(priority, taskID)
public:
    TaskManager(vector<vector<int>>& tasks) {
     //   fill(mp, mp+100001, make_pair(-1, -1));
        for(auto& t: tasks){
            int  u=t[0], i=t[1], p=t[2];
            maxI=max(maxI, i);
            mp[i]={p, u};
            pq.emplace(p, i);
        }
    }
    ~TaskManager(){
        memset(mp, -1, 8*(maxI+1));
    }
    void add(int userId, int taskId, int priority) {
        mp[taskId]={priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first=newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp[taskId].first=-1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (mp[i].first==p) {
                pq.pop();
                int u=mp[i].second;
                mp[i]={-1, -1}; // Remove task after execution
                return u;
            }
            pq.pop(); // Remove
        }
        return -1; // No valid tasks to execute
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
