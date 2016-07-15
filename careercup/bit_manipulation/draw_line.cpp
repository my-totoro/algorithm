/* 
 * 5.8 A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to
 * be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be
 * split across rows). The height of the screen, of course, can be derived from the length of the array
 * and the width. Implement a function that draws a horizontal line from (x1, y) to (x2, y).
 * The method signature look something like:
 * drawLine(byte[] screen, int width, int x1, int x2, int y)
 *
 */

#include<iostream>
#include<vector>
using std::vector;

class BadInput
{
public:
	BadInput() { std::cout << "BadInput\n"; }
};

void draw_line(vector<char> screen, int width, int x1, int x2, int y)
{
	int bytes_per_line = width / 8;
	int height = screen.size() / bytes_per_line;
	if (y < 0 || y > height - 1) throw BadInput{};
	if (x1 > x2) std::swap(x1, x2);
	//clear screen
	for (int i = 0; i < screen.size(); ++i) {
		screen[i] = 0;
	}

	int start_byte = y*bytes_per_line + x1 / 8;
	int start_bit = x1 % 8;
	int end_byte = y*bytes_per_line + x2 / 8;
	int end_bit = x2 / 8;

	int num_byte_to_set = (x2 - x1) / 8;
	if (num_byte_to_set > 0) {
		for (int i = 0; i < num_byte_to_set; ++i){
			screen[start_byte + i + 1] = 0xff;
		}
	}
	
	//set initial bytes
	screen[start_byte] |= -1 << start_bit;
	screen[end_byte] |= (1 << end_bit) - 1;

}


int main()
{
	return 0;
}