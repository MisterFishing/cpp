struct Student1
{
    char name[10];
    int number;
    int score;
};

char* GetName(struct Student1 * x);
void SetName(struct Student1 * x, char const* text);
