#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 64
#define BUFFER_SIZE 256

typedef struct EntryData {
	int id;
	int minute;
	int calories;
} EntryData;

// Check if any of the entries in the records have the given minute
bool has_minute_entry(EntryData* records, int num_records, int minute) {
	for (int i = 0; i < num_records; ++i) {
		if (records[i].minute == minute) {
			return true;
		}
	}

	return false;
}

typedef enum SentinelType {
	ST_INTEGER,
	ST_STRING
} SentinelType;

void insert_sentinel(char* position, SentinelType type);

// insert_sentinel(pos, ST_INTEGER);

// Inside insert_sentinel:
//
// if (type == ST_INTEGER) {
// 	...
// }

int main(void) {
	FILE* datafile = fopen("data.csv", "r");
	if (datafile == NULL) {
		puts("Failed to open datafile!");
		return -1;
	}

	EntryData records[MAX_RECORDS];
	int num_records = 0;

	char buffer[BUFFER_SIZE];

	// Read in target using strtok, get target ID
	int target_id = 0;

	fgets(buffer, BUFFER_SIZE, datafile);
	strtok(buffer, ","); // Discard first cell
	target_id = atoi(strtok(NULL, ","));

	printf("Target id: %i\n", target_id);

	// Skip the header line. Discard
	fgets(buffer, BUFFER_SIZE, datafile); // Reads line into buffer, ignore
	
	// Read in the next data line into a STRING, while there are
	// more lines to be read.
	while (fgets(buffer, BUFFER_SIZE, datafile) != NULL) {
		printf("Read line: %s", buffer);

		// Check for missing data, two consecutive commas.
		// Shifting commas over and inserting a sentinel value.
		
		// Track the number of commas we've passed, and use that to
		// determine what sentinel type to insert.
		
		// Iterate over string,
			// Check current char and next char,
			// If they're both commas, then we need to insert sentinel

		// Parse values using strtok
		records[num_records].id = atoi(strtok(buffer, ","));
		records[num_records].minute = atoi(strtok(NULL, ","));
		records[num_records].calories = atoi(strtok(NULL, "\n"));

		printf("ID: %i, minute: %i, calories: %i\n", records[num_records].id,
				records[num_records].minute, records[num_records].calories);
		
		// Maybe clean it here?
		
		// Clean any values that are illogical
		
		// Filter out the data if the ID doesn't match,
		bool target_matches = (records[num_records].id == target_id);
		bool has_minute = has_minute_entry(records, num_records, records[num_records].minute);
		bool valid_minute = (records[num_records].minute >= 0);

		printf("Target matches: %i, Duplicate minute: %i\n", (int)target_matches, (int)has_minute);

		if (target_matches && !has_minute && valid_minute) {
			++num_records;
		}
	}

	puts("\n\nFinal data:\n");
	for (int i = 0; i < num_records; ++i) {
		printf("%i,%i,%i\n", records[i].id, records[i].minute, records[i].calories);
	}

	fclose(datafile);

	return 0;
}

