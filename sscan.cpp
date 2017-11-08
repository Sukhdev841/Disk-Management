#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
  cout<<endl;
  for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

void s(vector<int> input,int head,int disk_length)
{
  vector<int> sscan,slook;
  bool left_reached= false,righ_reached = false;
  int left = 1;
  while(true)
  {
    int index = find(input.begin(),input.end(),head) - input.begin();
    if(index != input.size() && input[index] != -1)
    {
      sscan.push_back(input[index]);
      slook.push_back(input[index]);
      input[index] = -1;
    }
    if(left)
    {
      head--;
      if(head == 0)
      {
        sscan.push_back(0);
        left_reached = true;
        left = 0;
      }
    }
    else
    {
      head++;
      if(head == disk_length)
      {
        sscan.push_back(disk_length);
        righ_reached = true;
        left = 1;
      }
    }
    if(left_reached && righ_reached)
      break;
  }
  cout<<"\nS-Scan : ";
  print(sscan);
  cout<<"\nS-Look : ";
  print(slook);
  cout<<endl;
}

void c(vector<int> input,int head,int disk_length)
{
  vector<int> cscan,clook;
  int count = 0;
  while(true)
  {
    int index = find(input.begin(),input.end(),head) - input.begin();
    if(index != input.size() && input[index] != -1)
    {
      count++;
      cscan.push_back(input[index]);
      clook.push_back(input[index]);
    }
    head++;
    if(head == disk_length)
    {
      cscan.push_back(disk_length);
      cscan.push_back(0);
      head = 0;
    }
    if(count == input.size())
      break;
  }
  cout<<"\nC-Scan : ";
  print(cscan);
  cout<<"\nC-Look : ";
  print(clook);
  cout<<endl;
}

int main()
{
  ifstream fin;
  fin.open("input.txt");
  int n;
  fin>>n;
  vector<int> input(n);

  for(int i=0;i<n;i++)
  {
    fin>>input[i];
  }
  int head;
  fin>>head;

  //will go to 0 position first
  s(input,head,199);
  c(input,head,199);

  cout<<endl;

  fin.close();
}
