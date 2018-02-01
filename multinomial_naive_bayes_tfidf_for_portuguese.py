from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.pipeline import make_pipeline
from random import shuffle
from pprint import pprint
import numpy as np
import string
import nltk


def tokenize(text):
    """Tokenizes a text to an array of tokenized words

    :param text: a text string
    :return: an array of tokenized words
    """
    # test if null text
    if text == '':
        return text

    # replace punctuation for spaces
    for c in string.punctuation:
        text = text.replace(c, ' ')

    tokens = nltk.word_tokenize(text)
    return [token.lower() for token in tokens if token.isalpha()]


def stem(strs):
    """
    Stemmer for portuguese language
    :param strs: list of strings
    :return:
    """
    pt_stemmer = nltk.stem.RSLPStemmer()
    return [pt_stemmer.stem(string) for string in strs]


class NaiveBayesFaultEstimator:
    def __init__(self, data_set):
        self.data = data_set
        self.classifier = self.create_classifier()

    def create_classifier(self):
        self.dict_tag = {k: v for v, k in enumerate(set([d[0] for d in self.data]))}
        self.reverse_dict_tag = {v: k for k, v in self.dict_tag.items()}

        train_x = [' '.join(stem(tokenize(d[1]))) for d in self.data]
        train_y = np.asarray([self.dict_tag[d[0]] for d in self.data], dtype=np.int64)

        classifier = make_pipeline(TfidfVectorizer(), MultinomialNB())
        classifier.fit(train_x, train_y)
        return classifier

    def classify(self, text):
        """Classify text, returns classification name"""
        treated_text = [' '.join(stem(tokenize(text)))]
        prediction_ranking = self.classifier.predict(treated_text)
        return self.reverse_dict_tag[prediction_ranking[0]]

def get_data_set(fraction=0.1):
    data_set_negative = [
        ('negative', 'Eu não irei.'),
        ('negative', 'Paulo não estudou'),
        ('negative', 'Eu não irei buscá-la.'),
        ('negative', 'Não choveu hoje'),
        ('negative', 'Venha cá, você não vai apanhar.'),
        ('negative', 'Nunca mais mais faça isso.'),
        ('negative', 'Nem eu nem ela iremos.'),
        ('negative', 'Eu não assinei os documentos que você queria.'),
        ('negative', 'O relógio não quebrou com a queda.'),
        ('negative', 'Ela não me ama, disse isso ontem.'),
        ('negative', 'Não te amo, replicou ele.'),
        ('negative', 'Não há amor nessa terra.'),
        ('negative', 'Não somo heptacampeão.'),
        ('negative', 'Nunca diga que não me quer.'),
        ('negative', 'Ele não consertou o carro como pediu.'),
        ('negative', 'Ele não me pagou.'),
        ('negative', 'Nós não podemos nos falar agora'),
        ('negative', 'Não nos veremos mais.'),
        ('negative', 'Porque não te amo mais.'),
        ('negative', 'Não quero abraçá-la.'),
        ('negative', 'Não nos falaremos mais.')
    ]
    data_set_afirmative = [
        ('afirmative', 'Eu ganhei o jogo.'),
        ('afirmative', 'Mariana irá ao cinema hoje.'),
        ('afirmative', 'Com certeza iremos.'),
        ('afirmative', 'Ele fez a tarefa de casa.'),
        ('afirmative', 'Ela demorou e nós perdemos o trem.'),
        ('afirmative', 'Eu quero  o que é meu.'),
        ('afirmative', 'Assinarei os papéis.'),
        ('afirmative', 'Falaremos tudo amanhã.'),
        ('afirmative', 'Venha me buscar às 18h.'),
        ('afirmative', 'Ele está triste.'),
        ('afirmative', 'A ponte desabou.'),
        ('afirmative', 'Está chovendo.'),
        ('afirmative', 'Ele ficou quieto.'),
        ('afirmative', 'Bastou ela entrar para ele parar de falar.'),
        ('afirmative', '- Onde ele está? - Atrás do sofá, respondeu ela.'),
        ('afirmative', 'Você fez arte, logo vai apanhar.'),
        ('afirmative', 'Ela disse que me ama.'),
        ('afirmative', 'Foi ele quem disse.'),
        ('afirmative', 'A copa é nossa!'),
        ('afirmative', 'A copa será no Brasil.')
    ]
    shuffle(data_set_afirmative)
    shuffle(data_set_negative)
    test_set = data_set_afirmative[:int(fraction * len(data_set_afirmative))] + data_set_negative[:int(fraction * len(data_set_negative))]
    train_set = data_set_afirmative[int(fraction * len(data_set_afirmative)):] + data_set_negative[:int(fraction * len(data_set_negative)):]

    return test_set, train_set


if __name__ == '__main__':
    test, train = get_data_set(fraction=0.2)
    pprint('TRAIN SET: ')
    pprint(train)
    pprint('TEST SET:')
    pprint(test)
    estimator = NaiveBayesFaultEstimator(train)

    hits = 0
    for d in test:
        if d[0] == estimator.classify(d[1]):
            hits += 1
    print('Accuracy is:', hits / len(test))
