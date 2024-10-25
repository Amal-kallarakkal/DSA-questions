class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        string temp , check;
        sort(folder.begin(), folder.end());
        for(int i = 0 ; i < folder.size() - 1; i++) {
            check = folder[i];
            if(!check.size()) continue;
            for(int j = i + 1; j < folder.size(); j++) {
                if((folder[j].size() <= check.size()) || !folder[j].size()) continue;
                else {
                    temp = folder[j].substr(0, check.size());
                    if(temp == check && folder[j][check.size()] == '/' ) folder[j] = "";
                }
            }
        }
        sort(folder.rbegin(), folder.rend());
        while(folder[folder.size() - 1] == "") folder.pop_back();
        return folder;
    }
};