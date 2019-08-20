---
layout: post
title: Making blog in Github with jekyll
subtitle: github에서 블로그 만들기, 간단한 포스팅
date: 2019-07-24
categories: Github
tags: Github
author: windflower
---

github 블로그를 시작하면서 너무 많은 삽질을 하였기에 저와 제 팀원, 그리고 혹시 제 블로그를 들어오게 된 여러분을 위해 이 게시물을 작성합니다.

많은 분들이 이미 아시겠지만, github에서는 마크다운 문법으로 작성된 .md파일을 html파일로 알아서 바꿔준다는 장점이 있습니다.

#### 0. markdown editor install(스킵하셔도 무관합니다.)

1. Go to page https://atom.io/ and install
2. open atom
3. File->Settings->install
4. Search "markdown-preview-enhanced" and install

이제 우리는 atom을 이용하여 쉽게 마크다운 파일을 만들 수 있습니다.

#### 1. github에서 블로그 만들기/ jekyll theme 가져오기

ubuntu 18.0.4 환경에서 진행되는 방법입니다.

* 초기 설정 하기(공통)
```
sudo apt-get install ruby-full
sudo gem install jekyll bundler
```
* 초기 설정 하기(처음 만드는 관리자)

a. github에 가입합니다.

b. Repository를 만듭니다. Repository 이름은 계정명+github.io로 해야 github에서 제공하는 블로그 서비스를 이용하기 편합니다. (ex. CyberFlower.github.io)

c. 블로그를 장식할 배경인 theme을 가져옵니다. (노가다... ㄷㄷ)

d. \_posts에 글을 씁니다. 보통 파일명은 yyyy/mm/dd 형식의 날짜+이름으로 작성하는 것이 일반적이며, 이래야 정상적으로 굴러가는 theme이 많은 듯 합니다. (ex. 2019-07-24-test.md)

* 초기 설정 하기(관리자 초대를 받은 collaborators)

a. email을 통해 권한을 얻습니다.

b. 아래의 코드로 github에 연결합니다.
```
git clone https://github.com/CyberFlower/CyberFlower.github.io.git // repository를 clone합니다.
cd CyberFlower.github.io.git // 해당 폴더로 이동
git init // initialize git repository
```
초기 설정이 끝났으므로 2번으로 넘어갑니다.

#### 2. 리눅스상에서 쉽게 포스팅하는 command
블로그는 이미 만들어졌고, 파일을 변경하거나 추가해야 할 때 사용하게 되는 command이다. 파일 경로를 바꾸지 않는 이상 대부분의 경우 아래의 command만 잘 따라주면 이상한 에러로 고생할 일이 없습니다.
```
git pull origin master // 다른 사람이 update했을 수도 있으니 꼭 해줍시다!
파일 업데이트 또는 수정 과정을 진행하고...
git add . // 변경된 파일을 모두 추가
git commit -m "변경내용" // 스냅샷 기능을 하는 commit을 해주지 않으면 에러가 뜬다! 꼭 해주자...
git push origin master
```
중간에 에러만 뜨지 않는다면 위 4줄의 코드를 진행하면 됩니다.

#### 3. 중간에 자주 생기는 error 상황 극복하기

에러상황 극복에 관한 해결법은 제가 해결한 극히 제한적인 상황에서의 해결법입니다. 더 좋은 방법이 있다면 알려주세요.

a. rebase in progress; onto ~~~

```
git rebase --skip
2번 과정 반복
```

b. git error: failed to push some refers to ~~~

```
git pull origin master
message 입력창에 들어가면 CTRL+X로 탈출, 저장은 N
2번 과정 반복
```
