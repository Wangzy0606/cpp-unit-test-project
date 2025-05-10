// task1_logic.cpp
int findBroomHolder(int n, int time) {
    if (n <= 1) return 1; // 处理边界情况
    
    int position = 1;
    bool direction = true; // true表示向右，false表示向左
    
    for (int i = 0; i < time; ++i) {
        if (direction) {
            if (position == n) {
                direction = false;
                position--;
            } else {
                position++;
            }
        } else {
            if (position == 1) {
                direction = true;
                position++;
            } else {
                position--;
            }
        }
    }
    
    return position;
}    