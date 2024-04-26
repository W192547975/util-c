/* Copyright 2024 W192547975
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include	<stdlib.h>
#include	"bitpacker.h"

unsigned char *insert(unsigned char *dst,unsigned long src,int len)
{
	while(dst!=NULL&&len>0)
	{
		unsigned long n=src;
		unsigned cap=freelen(*dst);
		if(cap==0)return NULL;
		if(len>cap)n>>=len-cap;
		if(len<cap)
		{
			n<<=cap-len;
			if((src&1)==0)n|=(1ul<<cap-len)-1;
		}
		n&=(1ul<<cap)-1;
		*dst&=~((1u<<cap)-1);
		*dst|=n;
		if(len>=cap)dst++;
		len-=cap;
	}
	return dst;
}
