#include "counter.h"

//Prints the current counter number
void Counter::printCounter()
{
    int prev = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            ow::Unit temp{ zero_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 1) {
            ow::Unit temp{ one_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 2) {
            ow::Unit temp{ two_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 3) {
            ow::Unit temp{ three_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 4) {
            ow::Unit temp{ four_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 5) {
            ow::Unit temp{ five_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 6) {
            ow::Unit temp{ six_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 7) {
            ow::Unit temp{ seven_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 8) {
            ow::Unit temp{ eight_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
        else if (nums[i] == 9) {
            ow::Unit temp{ nine_img, prev, 0 };
            ow::Renderer::Draw(temp);
            prev += temp.getWidth();
        }
    }
}

//Adds 1 to the current counter and makes sure the vector contains single digits
void Counter::addCounter()
{
	int last = nums.size() - 1;
	nums[last]++;

    for (int i = last; i >= 0; --i) {
        if (nums[i] > 9) {
            nums[i] = 0;
            if (i > 0) {
                nums[i - 1]++;
            }
            else {
                nums.insert(nums.begin(), 1);
            }
        }
        else {
            break;
        }
    }
    printCounter();
}
