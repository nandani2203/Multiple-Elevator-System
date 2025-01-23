#include <string>
#include <vector>
#include <queue>

class Lobby {
public:
    struct Request {
        bool direction;  // True for Up, False for Down
        int floor;
        std::string elevator_id;  // Elevator assigned to this request (optional)
    };

    class Elevator {
    public:
        int curr_floor;
        int min_floor;
        int max_floor;
        std::string direction;
        bool is_assigned;
        std::vector<int> pushed_floors;
        std::string id;  // Elevator ID

        Elevator(int total_floors);

        void set_id(const std::string& id);
        void process_request(int floor, const std::string& new_direction);
        void complete_task();
        bool is_floor_in_range(int floor) const;
    };

private:
    int total_floors;
    std::vector<Elevator> elevators;
    std::queue<Request> requests;

    void delegate_requests();

public:
    Lobby(int num_elevators, int floors);
    ~Lobby();
    void generate_request(bool direction, int floor);
    bool no_requests() const;
    int find_best_elevator(const Request& req) const;
};
