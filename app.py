from flask import Flask, render_template, jsonify

from arduino import ser

app = Flask(__name__)

# works as the database
metro_data = {
    'total_count': 0,
    'total_validation': 0,
    'total_skippers': 0
}


@app.route('/')
def hello_world():
    return render_template('index.html')


@app.route('/data')
def data():
    """updates the database and returns the database as a json file"""
    if ser:
        raw = ser.read_all().strip()
        metro_data['total_count'] += len(raw)
        metro_data['total_validation'] += raw.count(b'1')
        metro_data['total_skippers'] += raw.count(b'0')
    return jsonify(metro_data)


# used for testing
@app.route('/add_validation')
def add_validation():
    metro_data['total_validation'] += 1
    return 'validated'


# used for testing
@app.route('/add_skip')
def add_skip():
    metro_data['total_skippers'] += 1
    return 'skip'


app.run()
