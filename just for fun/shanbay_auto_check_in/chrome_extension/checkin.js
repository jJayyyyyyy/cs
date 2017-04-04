function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function check(){
	var checkin_url = "https://www.shanbay.com/api/v1/checkin/?for_web=true";
	var reqCheckIn = new XMLHttpRequest();
	reqCheckIn.open("POST", checkin_url);
	reqCheckIn.send();
}

function getArticleList(){
	var req = new XMLHttpRequest();
	req.open("GET", "https://www.shanbay.com/api/v1/read/article/news/?ipp=15&page=1", false);
	req.send();
	var resp = req.responseText;
	var jsonResp = JSON.parse(resp);
	var articleList = jsonResp["data"]["articles"];
	return articleList;
}

function getArticlePage(article){
	var req = new XMLHttpRequest();
	var newsID = '' + article["id"];
	req.open("GET", "https://www.shanbay.com/read/article/" + newsID + "/");
	req.send();
	return req;
}

function putArticle(req, article){
	if( article['finished']===false ){
		var newsID = '' + article["id"];
		var minSec = '' + ( article["min_used_seconds"] + parseInt(Math.random()*60+60) );
		var fdArticle = new FormData();
		fdArticle.append("operation", "finish");
		fdArticle.append("used_time", minSec);
		var articleURL = "https://www.shanbay.com/api/v1/read/article/user/" + newsID + "/";
		req.open("PUT", articleURL);
		req.send(fdArticle);
	}
}

async function makeReadings() {
	var articleList = getArticleList();
	await sleep(5000);
	var req = getArticlePage( articleList[0] );
	await sleep(30000);
	putArticle(req, articleList[0]);
	await sleep(10000);

	req = getArticlePage( articleList[1] );
	await sleep(30000);
	putArticle(req, articleList[1]);
	await sleep(10000);

	// alert("Checked-In!");
	check();
}

makeReadings();

/*
function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function makeListening(){
	var getListenData = new XMLHttpRequest();
	getListenData.open("GET", "https://www.shanbay.com/api/v1/listen/usersentence/?level=1", false);
	getListenData.send();
	var listenData = JSON.parse(getListenData.responseText);

	await sleep(5000);

	for( var i=0; i<3; i++ ){
		var numScore = '' + listenData["data"][i]["blanks"].length;
		var articleID = '' + listenData["data"][i]["article_id"];
		var sentenceID = '' + listenData["data"][i]["sentence_id"];
		var fdListen = new FormData();
		fdListen.append("result", "1");
		fdListen.append("correct_ratio", "100");
		fdListen.append("delta_failed_times", "0");
		fdListen.append("num_hints", "0");
		fdListen.append("num_score", numScore);
		var ansListen = new XMLHttpRequest();
		ansListen.open("PUT", "https://www.sh	anbay.com/api/v1/listen/usersentence/" + articleID + '/' + sentenceID);
		ansListen.send(fdListen);
		await sleep(30000);
	}
}

makeListening();
*/
