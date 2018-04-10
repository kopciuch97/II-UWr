<?php

namespace src\Controllers\controller;
require_once __DIR__ . '/../../vendor/autoload.php';

use Money\Currency;
use Money\Money;
use Silex;
use src\DataProviders\JsonDataProvider;
use src\Deserializers\StandardDeserializer;
use src\Formatters\JsonFormatter;
use src\Products\SimpleProduct;
use src\Serializers\StandardSerializer;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;


$formatter = new JsonFormatter();
$serializer = new StandardSerializer(__DIR__ . '/../../data/objects/');
$deserializer = new StandardDeserializer(__DIR__ . '/../../data/objects/');
$provider = new JsonDataProvider($deserializer, $formatter);

$app = new Silex\Application();

$app->get('/products/{id}', function ($id) use ($app, $provider) {
  return new Response($provider->getOne($id));
});

$app->get('/products', function () use ($app, $provider) {
  return new Response($provider->getAll());
});

$app->post('/products', function (Request $request) use ($app, $serializer) {
  $product = new SimpleProduct(
    $serializer->getCounter() + 1,
    $request->get('name'),
    new Money($request->get('value'), new Currency($request->get('currency'))));
  $serializer->serialize($product);
  return new Response('Utworzono nowy produkt!');
});

$app->put('/products/{id}', function (Request $request, $id) use ($app, $serializer) {
    $product = new SimpleProduct(
      $id,
      $request->get('name'),
      new Money($request->get('value'), new Currency($request->get('currency'))));
    $serializer->serializeId($id, $product);
    return new Response('Zaktualizowano obiekt o id ' . $id);
});

$app->get('/', function () use ($app) {
  return $app->redirect('/products');
});

$app->error(function (\Exception $e, Request $request, $code) {
  switch ($code) {
    case 404:
      $message = 'The requested page could not be found.';
      break;
    default:
      $message = 'We are sorry, but something went terribly wrong.';
  }

  return new Response($message);
});

$app->run();




