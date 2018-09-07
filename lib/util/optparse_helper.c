#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "optparse_helper.h"

/**
 * Print ${text} word-wrapped at 80 characters, with a left margin of
 * ${leftmargin} spaces.  The first line is not indented.
 */
static void
print_wordwrap(FILE * stream, const char * text, const int startpos)
{
	const char * word;
	const char * space;
	const char * endpos;
	int first_on_line = 1;
	int linepos = startpos;

	word = text;
	endpos = text + strlen(text);

	while ((word < endpos)) {
		if ((space = strchr(word, ' ')) == NULL)
			space = endpos;
		int wordlen = space - word;

		/* Newline if necessary, but never for the first word. */
		if (!first_on_line && (linepos + wordlen + 1) > 80) {
			fprintf(stream, "\n%*c", startpos, ' ');
			linepos = startpos;
			first_on_line = 1;
		}

		if (first_on_line) {
			/* Print the first word, regardless of length. */
			fprintf(stream, "%.*s", wordlen, word);
			linepos += wordlen;
			first_on_line = 0;
		} else {
			/* Print a space, then the first word. */
			fprintf(stream, " %.*s", wordlen, word);
			linepos += wordlen + 1;
		}

		word += wordlen + 1;
	}
}

/**
 * print_help(description, args, num_args):
 * Print a --help message with a one-line ${description} and ${num_args}
 * nicely formatted arguments ${args}.
 */
void
print_help(FILE * stream, const char * description, const struct args * args,
    const size_t num_args)
{
	size_t i;
	size_t longest = 0;
	size_t length;
	size_t remaining;

	/* Print one-line description. */
	fprintf(stream, "%s\n\n", description);

	/* Find longest set of short + long + arg. */
	for (i = 0; i < num_args; i++) {
		length = strlen(args[i].arg_short) + strlen(args[i].arg_long)
		    + strlen(args[i].arg_optarg) + 2 + 2 + 1 + 2;
		if(longest < length)
			longest = length;
	}

	/* Print args. */
	for (i = 0; i < num_args; i++) {
		remaining = longest;

		fprintf(stream, "  ");
		remaining -= 2;

		fprintf(stream, "%s", args[i].arg_short);
		if((length = strlen(args[i].arg_short)) > 0) {
			fprintf(stream, ", ");
			remaining -= (length + 2);
		}

		fprintf(stream, "%s", args[i].arg_long);
		if((length = strlen(args[i].arg_long)) > 0) {
			fprintf(stream, " ");
			remaining -= (length + 1);
		}

		fprintf(stream, "%s", args[i].arg_optarg);
		if((length = strlen(args[i].arg_optarg)) > 0) {
			fprintf(stream, "  ");
			remaining -= (length + 2);
		}

		assert(remaining <= longest);

		if(remaining > 0)
			fprintf(stream, "%*c", (int)remaining, ' ');

		print_wordwrap(stream, args[i].arg_explain, longest);
		
		fprintf(stream, "\n");
	}
}

