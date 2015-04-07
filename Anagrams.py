class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        # di = dict.fromkeys(strs)
        di={}
        anas=[]
        iset=set()
        for e,s in enumerate(strs):
            t=''.join(sorted(list(s)))
            if t not in di:
                di[t]=s 
            else:
                if di[t] not in iset:
                    anas.append(di[t])
                    iset.add(di[t])
                anas.append(s)
                
                #del di[t]
        print di
        # for e,x in enumerate(strs):
            # if [x::-1] in di and e!=di[x[::-1]]
        #anas.extend([x for e,x in enumerate(strs) if x[::-1] in di and e!=di[x[::-1]]])
        return anas
        # for e,s in enumerate(strs):



if __name__ == '__main__':
    s = Solution()
    strs=['aca','dog','','cat','tac','god','','aca']
    strs2=['and','dan']
    strs3=['']
    print s.anagrams(strs3)