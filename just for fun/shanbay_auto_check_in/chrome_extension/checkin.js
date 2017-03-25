function listen(){
	var getListenData = new XMLHttpRequest();
	getListenData.open("GET", "https://www.shanbay.com/api/v1/listen/usersentence/?level=1", false);
	getListenData.send();
	var listenData = JSON.parse(getListenData.responseText);

	var i;
	for( i=0; i<1; i++ ){
		var numScore = '' + listenData["data"][i]["blanks"].length;
		var articleID = '' + listenData["data"][i]["article_id"] + '/';
		var sentenceID = '' + listenData["data"][i]["sentence_id"];
		var fdListen = new FormData();
		fdListen.append("result", "1");
		fdListen.append("correct_ratio", "100");
		fdListen.append("delta_failed_times", "0");
		fdListen.append("num_hints", "0");
		fdListen.append("num_score", numScore);
		var ansListen = new XMLHttpRequest();
		ansListen.open("PUT", "https://www.shanbay.com/api/v1/listen/usersentence/" + articleID + sentenceID);
		ansListen.send(fdListen);
	}
}

function reading(){
	var req = new XMLHttpRequest();
	req.open("GET", "https://www.shanbay.com/api/v1/read/article/news/?ipp=15&page=1", false);
	req.send();
	var resp = req.responseText;
	var jsonResp = JSON.parse(resp);
	var articles = jsonResp["data"]["articles"];
	var article = articles[0];

	var cnt=0;
	for( cnt=0; cnt<2; cnt++ ){
		var article = articles[cnt];
		if( article['finished']===false ){
			var newsID = '' + article["id"];
			var minSec = '' + ( article["min_used_seconds"] + parseInt(Math.random()*60+120) );
			var fdArticle = new FormData();
			fdArticle.append("operation", "finish");
			fdArticle.append("used_time", minSec);
			var articleURL = "https://www.shanbay.com/api/v1/read/article/user/" + newsID + "/";
			var aReq = new XMLHttpRequest;
			aReq.open("PUT", articleURL);
			aReq.send(fdArticle);
			var aResp = aReq.responseText;
		}
	}
}

function check(){
	var checkin_url = "https://www.shanbay.com/api/v1/checkin/?for_web=true";
	var reqCheckIn = new XMLHttpRequest();
	reqCheckIn.open("POST", checkin_url);
	reqCheckIn.send();
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function foo() {
  reading();
  await sleep(30000);
  reading();
  await sleep(5000);
  check();
  // alert("Checked-In!");
}


foo();


