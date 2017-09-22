#include<stdio.h>
#include<unistd.h>

struct InputBuffer_t 
{
	char* buffer;
	size_t buffer_length;
	ssize_t input_length;
};

typedef struct InputBuffer_t InputBuffer;

InputBuffer* new_input_buffer() 
{
	InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;

	return input_buffer;
}

void print_prompt() 
{
	printf("db > ");
}

ssize_t getline(char **lineptr, size_t  *n, FILE *stream);


int main(int argc, char* argv[]) 
{
	InputBuffer* input_buffer = new_input_buffer();
	while (1) 
	{
		print_prompt();
		read_input(input_buffer);

		if (strcmp(input_buffer->buffer, "exit") == 0) 
		{
			exit(EXIT_SUCCESS);
		}
		else 
		{
			printf("Unrecognized command '%s'.\n", input_buffer->buffer);
		}
	}
	printf("Hello world");
	getchar();
	return 0;
} 