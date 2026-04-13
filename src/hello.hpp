#include <string>
#include <vector>
using namespace std;
class Gradebook {
    private:
   vector <string> first_names;
    vector <string> last_names;
    vector<string> ids;
    vector <string> assignments;
    vector <int> assignments_points;
    vector<vector<int>> grades;
    public:
    void add_student(string first_name, string last_name, string id);
    void add_assignment(string assignments, int assignment_points);
    void add_grade(string id, string assignments, int grades);
 string report();
};
