#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
bool read(char name[]);
bool read(int& emNo);
bool read(double& emSal);

}
#endif // !SDDS_FILE_H_
