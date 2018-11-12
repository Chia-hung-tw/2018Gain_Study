#include "setup_config.h" 
#include <iostream>
#include <sstream>
#include <dirent.h>

setup_config::setup_config(){
  for(int i = 0 ; i < MAXBOARDS ; ++i){ Module_List[i] = 0; }
}
setup_config::~setup_config(){}
 
void setup_config::Make_dir(){
  char command[150];
  
  cout << "Creating output directories..., will skip if exist..." << endl;

  if( !DirectoryExists(dirpath.c_str()) ){
    cout << dirpath << " is not yet exist, creating ..." << endl;
    sprintf(command,"mkdir -p %s",dirpath.c_str());    }

  
  string outpath = string( dirpath + string("Module_Ntuple") );

  if( DirectoryExists(outpath.c_str()) ){
    cout << outpath << " has already exist, give up creating other dirs..."
	 << endl;
    return;}

  int file_check = 0;
  sprintf(command,"mkdir -p %s",outpath.c_str());
  cout << command << endl;
  file_check += system(command);

  char dirname[150];
  sprintf(dirname,"%s/TB",outpath.c_str() );
  sprintf(command,"mkdir -p %s",dirname);
  cout << command << endl;
  file_check += system(command);

  sprintf(dirname,"%s/Inj",outpath.c_str() );
  sprintf(command,"mkdir -p %s",dirname);
  cout << command << endl;
  file_check += system(command);

  string tpro_outpath = string( dirpath + string("Module_TProfile") );
  sprintf(dirname,"%s",tpro_outpath.c_str() );
  sprintf(command,"mkdir -p %s",dirname);
  cout << command << endl;
  file_check += system(command);

  
  cout << "Output directories has been created ... " << endl;
}

void setup_config::Read_Module_List(string Module_Layout){  
  ifstream infile(Module_Layout.c_str());
  string line;
  int line_count = 0;
  int members = 6;
  string line_contents[members];
  
  // Get the headers
  getline(infile,line); 
  getline(infile,line);
  int limit = sizeof(Module_List)/sizeof(int);
  while(true){
    getline(infile,line);
    if( infile.eof() || line_count == limit-1 ) {break;};
    std::istringstream iss(line);
    for(int i = 0 ; i < members ; ++i){
      getline(iss,line_contents[i], ',' );}
    int ModuleID = std::stoi( line_contents[0] );
    Module_List[line_count] = ModuleID;
    moduleID2BDorder.insert( std::pair<int,int>(ModuleID,line_count) );
    //cout << "Module "<< ModuleID << " correspond to BD " << line_count << endl;
    line_count++;
  }
  infile.close();
}

bool setup_config::DirectoryExists( const char* pzPath ){
    if ( pzPath == NULL) return false;
 
    DIR *pDir;
    bool bExists = false;
 
    pDir = opendir (pzPath);
 
    if (pDir != NULL)
    {
        bExists = true;    
        (void) closedir (pDir);
    }
 
    return bExists;
}