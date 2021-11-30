#include <iostream>
#include <time.h>

using namespace std;

int correct = 0;
int wrong = 0;
int number_q = 1;
bool ask[10] = {true, true, true, true, true, true, true, true, true, true};

void randomQuestion();
void displayAnswers();
void question(string question, string a, string b, string c, string d, char corr_answer);
void result();

int main()
{
	displayAnswers();
}

void displayAnswers()
{
	system("CLS");
	cout << "Question " << number_q << "\t\tCorrect answers: " << correct << "\t\tWrong answers: " << wrong << endl << endl;
	randomQuestion();
}

void randomQuestion()
{
	srand(time(NULL));
	bool not_shown_question = false;

	for (int i = 0; i < 10; i++)
	{
		if (ask[i])
		{
			not_shown_question = true;
			break;
		}
	}

	while (not_shown_question)
	{
		int randomN = rand() % 10;
		if (ask[randomN])
		{
			ask[randomN] = false;
			switch (randomN)
			{
			case 0:
				question("In Physics, what does 'V' stand for?", "Volume", "Speed", "Time", "Gravity", 'a');
				break;
			case 1:
				question("How much is the Earth's acceleration of gravity?", "420", "98", "0.98", "9.8", 'd');
				break;
			case 2:
				question("What does 'F' stand for?", "Free fall", "Facebook", "Force", "Density", 'c');
				break;
			case 3:
				question("What does an ohm measure?", "Temperature of plasma", "Volume of gas", "Air resistance", "Electrical resistance", 'd');
				break;
			case 4:
				question("Which of these things is named after Isaac Newton?", "Volume of water", "A type of telescope", "A videogame", "The air resistance", 'b');
				break;
			case 5:
				question("If an object is in motion, what kind of energy does it possess?", "Heat energy", "Potential energy", "Kinetic energy", "Metabolic energy", 'c');
				break;
			case 6:
				question("What is the force that holds an object from sliding?", "Friction", "Gravity", "Tension", "Momentum", 'a');
				break;
			case 7:
				question("What is the Earth's primary source of energy?", "The Earth's core", "The Sun", "The sea movements", "The Moon", 'b');
				break;
			case 8:
				question("What is the force that keeps us on the ground?", "Gravity", "Tension", "Friction", "Air resistance", 'a');
				break;
			case 9:
				question("Which scientist is famous for his Theory of Relativity?", "Copernicus", "Galileo", "Newton", "Einstein", 'd');
				break;
			}
		}
	}
	result();
}

void result()
{
	system("cls");
	cout << "Total questions: " << number_q - 1 << endl;
	cout << "Correct answers: " << correct << endl;
	cout << "Wrong answers: " << wrong << endl;
	if (correct > wrong)
	{
		cout << "Congratulations! You pass." << endl;
	}
	else if (wrong >= correct)
	{
		cout << "Sorry, you failed." << endl;
	}
}

void question(string question, string a, string b, string c, string d, char corr_answer)
{
	cout << question << endl;
	cout << "A.\t" << a << endl;
	cout << "B.\t" << b << endl;
	cout << "C.\t" << c << endl;
	cout << "D.\t" << d << endl;
	char answer;
	cin >> answer;
	if (answer == corr_answer)
	{
		correct++;
	}
	else
	{
		wrong++;
	}
	number_q++;
	displayAnswers();
}