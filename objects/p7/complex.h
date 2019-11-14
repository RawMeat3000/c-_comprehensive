#pragma once


class complex
{
public:
	complex();
	complex(int num_rows, int num_columns);

	complex(const complex& c);

	~complex();

	complex& operator=(complex& c);
	bool operator==(complex& c);
	bool operator!=(complex& c);
	friend ostream& operator<<(ostream &output, const complex &c);

	static bool display();
	static void set_display(bool flag);

	void setxy(int num1, int num2);

private:
	void _release();
	void _copy(const complex& c);

	char* string_rep;
	int num1 = 0;
	int num2 = 0;

	static bool is_output_displayed;

	int get_char_length(int num);
};