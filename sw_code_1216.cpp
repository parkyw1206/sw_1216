#include<iostream>

using namespace std;
bool checkPar(string s){
    for(int i = 0 ; i < s.size()/2 ; i++){
    	if(s[i] != s[s.size()-i-1])
            return false;
    }
    return true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T = 10,  test = 0, answer = 0;
    int frontI, endIn;
	char arr[100][100];
    string temp = "";
    bool flag = false;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{    
        cin >> test;
        answer = 0;
        for(int i = 0 ; i < 100 ; i++){
            	for(int j = 0 ; j < 100 ; j++)
               		cin >> arr[i][j];
        }
        
		for(int parLen = 0 ; parLen < 100 ; parLen++){
            
            // check rows
            for(int i = 0 ; i < 100 ; i++){
                frontI = 0;
                temp = "";
                endIn = parLen;
                for(int k = frontI ; k < endIn-1; k++)
                    temp.push_back(arr[i][k]);
                
                for(int j = 0 ; j < 100 - parLen +1 ; j++){
                    temp.push_back(arr[i][endIn-1]);
                    if(checkPar(temp) == true && parLen >= answer )
                         	answer = parLen;
                    temp.erase(temp.begin());
                    frontI ++;
                    endIn ++;
            	}   
            }
            // check cols
            for(int i = 0 ; i < 100; i++){
                frontI = 0;
                temp = "";
                endIn = parLen;
                for(int k = frontI ; k < endIn-1; k++){
                    temp.push_back(arr[k][i]);
                }
                for(int j = 0 ; j < 100 - parLen+1 ; j++){
                    temp.push_back(arr[endIn-1][i]);
                    if(checkPar(temp) == true && parLen >= answer )
                            answer = parLen;
                
                    temp.erase(temp.begin());
                    frontI ++;
                    endIn ++;
            	}
        	}	
        }
   		cout << "#" << test << " " << answer << endl;
	}
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}