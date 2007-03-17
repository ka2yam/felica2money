/*
 * ImportMoney : Convert Bank csv file to MS Money OFX file.
 *
 * Copyright (c) 2001, Takuya Murakami. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
#include <vcl.h>
#pragma hdrstop

#include "Account.h"

Cards::Cards(void)
{
	num_cards = 0;
}

void Cards::AddCard(Card *card)
{
	cards[num_cards] = card;
	num_cards++;
}       

TransactionList * Cards::ReadCard(AnsiString SFCPeepPath, Card **matchcard)
{
	TransactionList *t;

	for (int i=0; i<num_cards; i++) {
        	cards[i]->SetSFCPeepPath(SFCPeepPath);
		t = cards[i]->ReadCard();
		if (t) {
			*matchcard = cards[i];
			return t;
		}
	}
	Application->MessageBox("カードを読むことができませんでした",
				"エラー", MB_OK);
	return NULL;
}

	
