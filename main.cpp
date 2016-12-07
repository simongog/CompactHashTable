#include "cht.h"
/* arguments
 * 1 nodeNum
 * 2 alphabet = sigma
 * 3 dataset
 * 4 loadFactor = 0.8
 * 5 searchFile
*/
void printSpace(cht*);


int main(int argc, char *argv[])
{
    if(argc < 5) {
        cerr << "Use " << argv[0] << " <universe> <n> <epsilon> <satDataWidth>" << endl;
        exit (-1);
    }
    //args
    unsigned long long universe = atoll(argv[1]);
    unsigned long long n = atoll(argv[2]);
	double epsilon = atof(argv[3]);
	unsigned long long satDataWidth = atoll(argv[4]);
    unsigned long long M = (1+epsilon)*n+1;

    cht *c=new cht(universe, n, satDataWidth, epsilon, 0);
    //fill it up
    bit_vector b(M,0);
    cout<<"insert"<<endl;
    unsigned long long key, value;
    for (unsigned long long i=0; i<n; i++){
    	value = lrand48()%(1<<satDataWidth);
    	key = lrand48()%M;
    	while (b[key] == 1){
    		key = (key+1)%M;
    	}
    	c->insert(key,value);
    	b[key]=0;
    }
    unsigned long long valueFound=0;
    cout<<"find"<<endl;
    for (unsigned long long i=0; i<n; i++){
    	if(b[i] == 1)
    		valueFound = c->find(i);
    	if(valueFound == (1<<satDataWidth))
    		cout<<"notFound"<<endl;
    }
    printSpace(c);
return 0;
}

void printSpace(cht* c){
cout << "space in bits (per M): "<<endl;
cout << "quotient_items: "<< size_in_bytes(c->quotient_items)/(double)c->M*8<< endl;
cout << "\t-> quotients: "<< ((size_in_bytes(c->quotient_items)/(double)c->M)*8.0)-c->satWidth;
cout << "\t satDataWidth: " <<c->satWidth<<endl;
cout << "cht (V+C): " << (size_in_bytes(c->V) + size_in_bytes(c->C))*8.0/(double)c->M<< endl;

}