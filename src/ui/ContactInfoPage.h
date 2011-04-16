/* Torsion - http://torsionim.org/
 * Copyright (C) 2010, John Brooks <john.brooks@dereferenced.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following disclaimer
 *      in the documentation and/or other materials provided with the
 *      distribution.
 *
 *    * Neither the names of the copyright owners nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CONTACTINFOPAGE_H
#define CONTACTINFOPAGE_H

#include <QWidget>

class ContactUser;
class QLabel;
class QTextEdit;

class ContactInfoPage : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ContactInfoPage)

public:
    ContactUser * const user;

    explicit ContactInfoPage(ContactUser *user, QWidget *parent = 0);
    ~ContactInfoPage();

public slots:
    void saveNotes();

private slots:
    void setNickname();
    void deleteContact();

protected:
    virtual void hideEvent(QHideEvent *);

private:
    class QAction *renameAction, *deleteAction;

    QLabel *avatar;
    class EditableLabel *nickname;
    QTextEdit *notesEdit;

    void createActions();
    void createAvatar();
    class QLayout *createInfo();
    class QLayout *createButtons();
    class QLayout *createRequestInfo();
    void createNotes(class QBoxLayout *layout);
};

#endif // CONTACTINFOPAGE_H
