#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node
{
    int Node_no;
    Node *next;

    Node(int s)
    {
        Node_no = s;
        next = NULL;
    }
};

struct List
{
    int id;
    int count;
    int Node_no;
    Node *head;
};

class Graph
{
    private:
        int no_of_vertex;
        List *vertex_layer_1;
        List *vertex_layer_2;

    public: 
        Graph()
        {
            no_of_vertex = 0;
            vertex_layer_1 = NULL;
            vertex_layer_1 = NULL;
        }

        void set_vetex(int no)
        {
            no_of_vertex = no;
            vertex_layer_1 = new List[no];
            vertex_layer_2 = new List[no];
            for(int i=0; i<no; i++)
            {
                // Layer 1
                vertex_layer_1[i].id = 0;
                vertex_layer_1[i].count = 0;
                vertex_layer_1[i].Node_no = i+1;
                vertex_layer_1[i].head = NULL;
                // Layer 2
                vertex_layer_2[i].id = 0;
                vertex_layer_2[i].count = 0;
                vertex_layer_2[i].Node_no = i+1;
                vertex_layer_2[i].head = NULL;
            }
        }

        void add_edge(int source, int destination)
        {   
            Node *new_node_dest = new Node(destination);
            if(vertex_layer_1[source-1].head==NULL)
            {
                vertex_layer_1[source-1].head = new_node_dest;
            }else{
                Node *src =  vertex_layer_1[source-1].head;
                while(src->next != NULL)
                {
                    src = src->next;
                }
                src->next = new_node_dest;
            }

            Node *new_node_src = new Node(source);
            if(vertex_layer_2[destination-1].head==NULL)
            {
                vertex_layer_2[destination-1].head = new_node_src;
            }else{
                Node *dest =  vertex_layer_2[destination-1].head;
                while(dest->next != NULL)
                {
                    dest = dest->next;
                }
                dest->next = new_node_src;
            }
        }

        void generate_node_id_start(string layer)
        {
            List *arr;
            if(layer=="layer_1"){
                arr = vertex_layer_1;
            }else if(layer=="layer_2"){
                arr = vertex_layer_2;
            }else{
                cout<<"Enter Correct Layer"<<endl;
                return;
            }
            int count = 1;
            for(int i=0; i<no_of_vertex; i++)
            {
                arr[i].id = count;
                arr[i].count = count;
                Node *temp = arr[i].head;
                while(temp != NULL)
                {
                    count++;
                    temp = temp->next;
                }
            }
        }

        void generate_node_id_end(string layer)
        {
            List *arr;
            List *arr_1;
            if(layer=="layer_1"){
                arr = vertex_layer_1;
                arr_1 = vertex_layer_2;
            }else if(layer=="layer_2"){
                arr = vertex_layer_2;
                arr_1 = vertex_layer_1;
            }else{
                cout<<"Enter Correct Layer"<<endl;
                return;
            }
            for(int i=0; i<no_of_vertex; i++)
            {
                int small = 100;
                int find = 0;
                Node *temp = arr[i].head;
                while(temp != NULL)
                {
                    for(int j=0; j<no_of_vertex; j++)
                    {
                        if(temp->Node_no==arr_1[j].Node_no)
                        {
                            find = j;
                            break;
                        }
                    }
                    if(small > arr_1[find].count)
                    {
                        small =  arr_1[find].count;
                    }
                    arr_1[find].count += 1;
                    temp = temp->next;
                }
                arr[i].id =  small;
                arr[i].count =  small;
            } 
        }

        void print()
        {
            cout<<"Bipartite Graph"<<endl<<endl;
            cout<<"Layer 1"<<endl;
            for(int i=0; i<no_of_vertex; i++)
            {
                cout<<"Node "<<vertex_layer_1[i].Node_no<<": [ ";
                Node *temp = vertex_layer_1[i].head;
                while(temp != NULL)
                {
                    cout<<temp->Node_no<<" ";
                    temp = temp->next;
                }
                cout<<"]"<<endl;
            }
            cout<<endl;

            cout<<"Layer 2"<<endl;
            for(int i=0; i<no_of_vertex; i++)
            {
                cout<<"Node "<<vertex_layer_2[i].Node_no<<": [ ";
                Node *temp_1 = vertex_layer_2[i].head;
                while(temp_1 != NULL)
                {
                    cout<<temp_1->Node_no<<" ";
                    temp_1 = temp_1->next;
                }
                cout<<"]"<<endl;
            }

            cout<<endl<<"Node Id Layer 1 : [ ";
            for(int i=0; i<no_of_vertex; i++)
            {
                cout<<vertex_layer_1[i].id<<" ";
            }
            cout<<"]"<<endl;

            cout<<"Node Id Layer 2 : [ ";
            for(int i=0; i<no_of_vertex; i++)
            {
                cout<<vertex_layer_2[i].id<<" ";
            }
            cout<<"]"<<endl;
        }
        
        List *get_graph_layer_1()
        {
            return vertex_layer_1;
        }

        List *get_graph_layer_2()
        {
            return vertex_layer_2;
        }
};  

void Quick_Sort(List *array, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = array[(i+j)/2].id;
    while(i<=j)
    {
        while(array[i].id<pivot)
        {
            i++;
        }   
        while(array[j].id > pivot)
        {
            j--;
        }   
        if(i<=j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if(j>start)
    {
        Quick_Sort(array, start, j);
    }
    if(i<end)
    {
        Quick_Sort(array, i, end);
    }
}

void store_id(int *arr, List *layer, int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = layer[i].id;
    }
}

bool is_equal(int *arr, List *layer, int n)
{
    bool check = false;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==layer[i].id)
        {
            check = true;
        }else{
            check = false;
            break;
        }
    }
    return check;
}

void calcualting_crossings(List *layer_1, List *layer_2, int n) 
{
	int cross = 0;
	int layer_2_idx[n] = {0};

    for(int i=0; i<n; i++) 
    {
		layer_2_idx[layer_2[i].Node_no-1] = i;
	}

	for(int i=0; i<n-1; i++) 
	{
		Node *temp = layer_1[i].head;
		while(temp != NULL) 
		{
			int check_1 = layer_2_idx[temp->Node_no-1];
			for(int j=i+1; j<n; j++) 
			{
				Node* temp_1 = layer_2[j].head;
				while(temp_1 != NULL) 
				{
					int check_2 = layer_2_idx[temp_1->Node_no-1];
					if(check_2 < check_1) 
                    {
						cross++;
					}
					temp_1 = temp_1->next;
				}
			}
			temp = temp->next;
		}
	}
    cout<<"Crossing: "<<cross<<endl;
}

void cuts(List *layer_1, List *layer_2, int no_of_vertex)
{
    int cuts[no_of_vertex-1] = {0};
    for(int i=0; i<no_of_vertex; i++)
    {
        Node *temp = layer_1[i].head;
        while(temp != NULL)
        {
            if(abs(temp->Node_no-layer_1[i].Node_no)>0 && temp->Node_no>=layer_1[i].Node_no)
            {
                int t = abs(temp->Node_no-layer_1[i].Node_no);
                int rex = i;
                while(t!=0)
                {
                    cuts[rex] += 1;
                    t--;
                    rex++;
                }
            }
            temp = temp->next;
        }
        Node *temp_1 = layer_2[i].head;
        while(temp_1 != NULL)
        {
            if(abs(layer_2[i].Node_no-temp_1->Node_no)>0 && temp_1->Node_no>=layer_2[i].Node_no)
            {
                int t = abs(layer_2[i].Node_no-temp_1->Node_no);
                int rex = i;
                while(t!=0)
                {
                    cuts[rex] += 1;
                    t--;
                    rex++;
                }
            }
            temp_1 = temp_1->next;
        }
    }
    int total = 0;
    cout<<"Cuts: [ ";
    for(int i=0; i<no_of_vertex-1; i++)
    {
        cout<<cuts[i]<<" ";
        total += cuts[i];
    }
    cout<<"]"<<endl;
    cout<<"Total Cuts: "<<total<<endl;
}

int main()
{
    string filename = "";
    cout<<"Enter Filename to make Graph: ";
    cin>>filename;
    cout<<endl;
    fstream newfile;
    newfile.open(filename, ios::in);

    Graph graph;
    string line = "";
    int no_of_vertex = 0;
    while(getline(newfile, line))
    { 
        if(no_of_vertex==0)
        {
            no_of_vertex = stoi(line);
            graph.set_vetex(stoi(line));
        }else{
            graph.add_edge(int(line[0])-48, int(line[line.length()-1])-48);
        }
    }
    newfile.close();

    // Min Sort Algorithum
    List *layer_1 = graph.get_graph_layer_1();
    List *layer_2 = graph.get_graph_layer_2();

    int layer_1_id[no_of_vertex] = {0};
    int layer_2_id[no_of_vertex] = {0};

    store_id(layer_1_id, layer_1, no_of_vertex);
    store_id(layer_2_id, layer_2, no_of_vertex);

    bool layer_1_check = false;
    bool layer_2_check = false;

    int checker = 0;
    int itr = 1;
    while(layer_1_check!=true && layer_2_check!=true)
    {
        cout<<"Iteration "<<itr<<endl;
        itr++;
        layer_1_check =  layer_2_check = false;
        if(checker!=0)
        {    
            Quick_Sort(layer_1, 0, no_of_vertex-1);
        }
        graph.generate_node_id_start("layer_1");
        graph.generate_node_id_end("layer_2");
        graph.print();
        cuts(layer_1, layer_2, no_of_vertex);
        calcualting_crossings(layer_1, layer_2, no_of_vertex);
        if(is_equal(layer_1_id, layer_1, no_of_vertex)==true)
        {
            layer_1_check = true;
        }else{
            store_id(layer_1_id, layer_1, no_of_vertex);
        }
        cout<<endl<<"--------------------------------"<<endl<<endl;  

        cout<<"Iteration "<<itr<<endl;
        itr++;
        Quick_Sort(layer_2, 0, no_of_vertex-1);
        graph.generate_node_id_start("layer_2");
        graph.generate_node_id_end("layer_1");
        graph.print();
        cuts(layer_1, layer_2, no_of_vertex);
        calcualting_crossings(layer_1, layer_2, no_of_vertex);
        if(is_equal(layer_2_id, layer_2, no_of_vertex)==true)
        {
            layer_2_check = true;
        }else{
            store_id(layer_2_id, layer_2, no_of_vertex);
        }
        cout<<endl<<"--------------------------------"<<endl<<endl;  
        checker++;
    }
       
    return 0;
}
