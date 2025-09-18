
// 3408. Design Task Manager
// https://leetcode.com/problems/design-task-manager/


#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;


class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const vector<int>& task : tasks) {
            int userId = task[0], taskId = task[1], prio = task[2];
            task_user_prio[taskId] = {userId, prio};
            prio_task[prio].emplace(taskId);
        }
    }

    void add(int userId, int taskId, int priority) {
        task_user_prio[taskId] = {userId, priority};
        prio_task[priority].emplace(taskId);
    }

    void edit(int taskId, int newPriority) {
        pair<int, int> user_prio = task_user_prio[taskId];
        rmv(taskId);
        user_prio.second = newPriority;
        add(user_prio.first, taskId, newPriority);
    }

    void rmv(int taskId) {
        pair<int, int> user_prio = task_user_prio[taskId];
        int prio = user_prio.second;
        if (prio_task[prio].size() == 1) {
            prio_task.erase(prio);
        } else {
            prio_task[prio].erase(taskId);
        }
        task_user_prio.erase(taskId);
    }

    int execTop() {
        if (prio_task.empty()) {
            return -1;
        }
        set<int, greater<int>>& top_prio_tasks = prio_task.rbegin()->second;
        int taskId = *top_prio_tasks.begin();
        auto [user, _] = task_user_prio[taskId];
        rmv(taskId);
        return user;
    }

private:
    unordered_map<int, pair<int, int>> task_user_prio;
    map<int, set<int, greater<int>>> prio_task;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
