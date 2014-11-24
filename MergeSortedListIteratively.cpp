struct Node
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* MergeLinksIteratively(ListNode *pHead1,ListNode* pHead2)
{
	if(pHead1==NULL)
		return pHead2;
	if(pHead2==NULL)
		return pHead1;

	//struct ListNode *pNewHead;   //C++中struct定以后不用再加struct
	ListNode *pNewHead = NULL;
	if(pHead1->m_nValue > pHead2->m_nValue)
	{
		pNewHead=pHead2;
		pHead2=pHead2->m_pNext;
	}
	else
	{
		pNewHead=pHead1;
		pHead1=pHead1->m_pNext;
	}
	ListNode *current = pNewHead;
	while(pHead1!=NULL && pHead2!=NULL)
	{
		if(pHead1->m_nValue > pHead2->m_nValue)
		{
			current->m_pNext=pHead2;
			current=pHead2;
			pHead2=pHead2->m_pNext;
		}
		else
		{
			current->m_pNext=pHead1;
			current=pHead1;
			pHead1=pHead1->m_pNext;

		}

	}
	if(pHead1!=NULL)
	{
		current->m_pNext=pHead1;
	}
	if(pHead2!=NULL)
	{
		current->m_pNext=pHead2;
	}

	return pNewHead;
}