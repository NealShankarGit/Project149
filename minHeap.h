#include <iostream>
#include <vector>

struct Employee {
    // Information stored in employee struct
    int id;
    int totalTasks;
    int taskCompletionRate;
    int errorRate;
    int attendance;
    int productivityScore;

    // Way to compare employees
    bool operator>(const Employee& other) const {
        return this->productivityScore > other.productivityScore;
    }
};

class minHeap {
    // Vector storing employee information
    std::vector<Employee> arr;
    // Heapify function to maintain heap properties once employee inserting into heap
    void heapify(int idx) {
        // Left and right indexes are children of parent (idx)
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        // Smallest stores index of lowest productivity score
        int smallest = idx;
        if(left < this->arr.size() && this->arr[left].productivityScore < this->arr[idx].productivityScore)
            smallest = left;
        if(right < this->arr.size() && this->arr[right].productivityScore < this->arr[smallest].productivityScore)
            smallest = right;
        // If smallest changed from original parent, swap the two employees and call function again on swapped employee
        if(smallest != idx)
        {
            std::swap(this->arr[idx], this->arr[smallest]);
            this->heapify(smallest);
        }
    }
    public:
    // Returns if the vector storing the employees is empty
    bool empty() {return this->arr.size() == 0;}
    // Insertion Function
    void insert(Employee person)
    {
        // Push the employee back to the end of the employee vector
        this->arr.push_back(person);
        // Gather index of employee and its parent
        int idx = this->arr.size() - 1;
        int parent = (idx - 1) / 2;
        // While employee is not the top of the heap and parent has higher productivity score
        // than inserted employee, switch the employees and repeat
        while(idx != 0 && this->arr[parent].productivityScore > this->arr[idx].productivityScore)
        {
            std::swap(this->arr[idx], this->arr[parent]);
            idx = parent;
            parent = (idx - 1) / 2;
        }
    }
    // Extract function
    void extract()
    {
        // If array size is empty, nothing to extract
        if(this->empty())
            return;
        // If array only has one employee, extract and return
        if(this->arr.size() == 1)
        {
            this->arr.pop_back();
            return;
        }
        // If array has more than one employee, bring last employee to top
        // and remove it from the back
        this->arr[0] = this->arr[this->arr.size() - 1];
        this->arr.pop_back();
        // Heapify the new root
        this->heapify(0);
    }
    // Top Function
    Employee top() 
    {
        // Return top of heap, first in arr if it is not empty
        if(!this->empty())
        {
            return this->arr[0];
        }
        // If empty, return negatives for employee attributes
        return {-1, -1, -1, -1, -1, -1};
    }
    // Search Function
    Employee search(int id)
    {
        // Iterating through every employee in the employee vector
        for(auto& person : this->arr)
        {
            // When ID is found in arr, return performance number
            if(person.id == id)
            {
                return person;
            }
        }
        // If ID not found, return -1 for employee attributes
        return {-1, -1, -1, -1, -1, -1};
    }
};