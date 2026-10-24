class Solution {
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
         vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;
            for (int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            return total;
        };

        int a1 = convert(aA);
        int a2 = convert(lA);
        int b1 = convert(aB);
        int b2 = convert(lB);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};