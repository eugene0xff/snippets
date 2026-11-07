import std;

int main() {
    {
        int apple_count;
        std::println("{}", apple_count);
    }

    {
        int apple_count{15};
        std::println("{}", apple_count);
    }

    {
        int apple_count{15};
        int orange_count{5};
        int total_fruit{apple_count + orange_count};
        std::println("{} {} {}", apple_count, orange_count, total_fruit);
    }

    {
        int lemon_count(4);
        int tomato_count = 12;
        std::println("{} {}", lemon_count, tomato_count);
    }

    {
        int banana_count(7.5);
        int tangerine_count = 5.3;
        std::println("{} {}", banana_count, tangerine_count);
    }

    {
        // will not compile
        //int papaya_count{0.3};
    }

    {
        int foot_count{2}, toe_count{10}, head_count{1};
        std::println("{} {} {}", foot_count, toe_count, head_count);
    }
}