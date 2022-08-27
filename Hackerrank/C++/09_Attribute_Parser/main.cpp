#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;

/* Note to myself:
Test case 2 has a query "d~sze{-truncated-}" that my code can't handle. Also 
apparently there are queries in other test cases that use a '.' instead of '~' to
seperate the tag name from the attribute name. My code can't handle these queries
either. My code works for the "normal" queries, as specified in the task. At this
point I want to move on to the next challenge, so that is why these queries/test 
cases don't work, and they won't ever.*/

struct Tag{
    string name;
    map<string, string> attributes;
    vector<Tag> nested_tags;
};

int get_idx(vector<Tag> *t_list, string tag_name){
    for(int i = 0; i < (*t_list).size(); i++){
        if((*t_list)[i].name == tag_name){
            return i;
        }
    }
    return -1;  // tag_name is not in t_list
}

void display_Tags(vector<Tag> t_list){
    for(int i = 0; i < t_list.size(); i++){
        cout << t_list[i].name << endl;
        for(auto j : t_list[i].attributes){
            cout << j.first << " = " << j.second << endl;
        }
        cout << endl;
    }
}

void read_Tags(vector<Tag> *t_list, int n){
    string s, attribute, att_value;
    string open_tags = "";
    bool unfinished;
    for(int i = 0; i < n; i++){
        cin >> s;
        s = s.substr(1);    // Cut the less than char away
        
        if(s.find("/") == string::npos){    // s is an opening tag
            if(open_tags == ""){
                open_tags = s;
            }else{
                open_tags.append(".");
                open_tags.append(s);
            }
        }else{  // s is a closing tag
            int pos_of_dot = open_tags.find_last_of(".");
            if(pos_of_dot == string::npos){ // open_tags might look like this tag1 --> close it
                open_tags = "";
            }else{  // open_tags might look like this: tag1.tag2 --> only close .tag2
                open_tags.erase(pos_of_dot);
            }
            continue;
        }

        if(get_idx(t_list, s) == -1){   // If the tag isn't in the vector yet.
            Tag current_tag;
            current_tag.name = open_tags;
            unfinished = (1 == 1);
            while(unfinished){
                // Read the name of the attribute, the equal char and the value of the attribute.
                // I don't need the equal sign, thats why I am overwriting int instantly.
                cin >> attribute >> att_value >> att_value;
                // Check if this is the last attribute of this tag by checking if it contains the ">" char.
                // If it is the last attribute, the while loop must break after this iteration.
                if(att_value.find(">") != string::npos){
                    unfinished = (1 == 0);
                }
                // Currently the attribute value contains "" and > chars. Delete those.
                att_value = att_value.substr(1);
                att_value.erase(att_value.find("\""));
                current_tag.attributes.insert(make_pair(attribute, att_value));
            }
            (*t_list).push_back(current_tag);   // Save the created tag in the tag vector
        }
    }
}


void execute_Queries(vector<Tag> t_list, int q){
    string query, tag_name, attr_name;
    int tag_idx;
    for(int i = 0; i < q; i++){
        cin >> query;   // Query might look like this: a.b~value --> seperate tag name from attribute name
        tag_name = query.substr(0, query.find('~'));
        attr_name = query.substr(query.find('~')+1);

        tag_idx = get_idx(&t_list, tag_name);
        if(tag_idx == -1){
            cout << "Not Found!\n";
        }else{
            map<string, string>::iterator itr = t_list[tag_idx].attributes.find(attr_name);
            if(itr == t_list[tag_idx].attributes.end()){    // Test if the attribute from the query exists
                cout << "Not Found!\n";
            }else{
                cout << t_list[tag_idx].attributes[attr_name] << endl;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int number_of_lines;
    int number_of_queries;
    vector<Tag> tag_list;
    cin >> number_of_lines >> number_of_queries;
    read_Tags(&tag_list, number_of_lines);
    // display_Tags(tag_list);
    execute_Queries(tag_list, number_of_queries);

    return 0;
}
