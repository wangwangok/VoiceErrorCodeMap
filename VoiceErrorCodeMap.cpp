// VoiceErrorCodeMap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

class ErrorCodeDecode {
private:
	uint64_t error_code;
	unsigned long domain;
	int16_t signedValue;
	uint16_t unSignedValue;
public:
	ErrorCodeDecode(uint64_t code) {
		error_code = code;
		domain = 0;
		signedValue = 0;
		unSignedValue = 0;
	}

	/// >> 16

	void unsigned_decode() {
		 unsigned long shift_right_16_value = error_code >> 16; /// domain
		 std::cout << "domain: " << shift_right_16_value << std::endl;
		 domain = shift_right_16_value;
		 int16_t signed_low_bit = error_code & 0xffff;
		 signedValue = signed_low_bit;
		 uint16_t unsigned_low_bit = error_code & 0xffff;
		 unSignedValue = unsigned_low_bit;
	}

	int16_t getSignedValue() {
		return signedValue;
	}

	uint16_t getUnSignedValue() {
		return unSignedValue;
	}
};

int main(int argc, const char *argv[])
{
	/// -x 十六进制数据
	/// -d 十进制数据
	using namespace std;
	if (argc < 1)
	{
		return 0;
	}
	try
	{
		int number = (int)std::strtol(argv[1], NULL, 0);
		ErrorCodeDecode ecd(number);
		ecd.unsigned_decode();
		cout << "无符号数：" << ecd.getUnSignedValue() << endl;
		cout << "有符号数：" << ecd.getSignedValue() << endl;
	}
	catch (const std::exception&)
	{

	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
