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

#ifndef BITBUF_T
typedef long bitbuf_t;
#define BITBUF_T bitbuf_t
#define CAP 26
#define LENMAX 037l
#define BUFMAX 0x3FFFFFFl
#endif

#define GETLEN(buf)		( (buf)>>CAP & LENMAX )
#define SETLEN(buf,len)	( ((buf)&~(LENMAX<<CAP)) | ((len)&LENMAX)<<CAP )
#define ADDLEN(buf,len)	SETLEN(buf,GETLEN(buf)+(BITBUF_T)(len))
#define WRITEBUF(buf,num,from,len)	( ((buf)&~(BUFMAX>>(from))) | ((num)<<(CAP-(len))&BUFMAX)>>(from) )
#define WRITE(buf,num,len)	WRITEBUF(ADDLEN(buf,len),num,(int)GETLEN(buf),len)

#define READ(buf,len)	( ((buf)&BUFMAX)>>(CAP-(len)) & ((1l<<(len))-1l) )
#define CLEAR(buf,len)	( (ADDLEN(buf,-(len))&~BUFMAX) | ((buf)<<(len)&BUFMAX) )
