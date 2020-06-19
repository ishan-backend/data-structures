string Solution::simplifyPath(string path) 
{
        vector<string> stk;
        stringstream ss(path);
        string tmp, res;
        
        while(getline(ss, tmp, '/'))
        {
            if(tmp == "" or tmp == ".") continue;
            else if(tmp == ".." and stk.size()) stk.pop_back();
            else
            {
                if(tmp != "..")
                {
                    stk.push_back(tmp);
                }
            }
        }
        
        for(auto str: stk)
        {
            res += "/"+str;
        }
        
        if(res.empty())
        {
            res += "/"; return res;
        }
        else
        {
            return res;
        }
        
}
