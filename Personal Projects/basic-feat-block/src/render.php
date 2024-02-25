<?php
  $feat_Title = $attributes['featTitle'];
  $feat_Prerequisites = $attributes['featPrerequisites'];
  $feat_Benefits = $attributes['featBenefits'];
  $show_Special_Field = $attributes['showSpecialField'];
  $feat_Specials = $attributes['featSpecials'];
?>

<div <?php echo get_block_wrapper_attributes(); ?>>
	<h4><?php echo esc_html( $feat_Title ); ?></h4>
  <p><strong>Prerequisite(s): </strong><?php echo esc_html( $feat_Prerequisites) ?></p>
  <p><strong>Benefit(s): </strong><?php echo esc_html( $feat_Benefits) ?></p>
  <?php if ($show_Special_Field): ?>
    <p><strong>Special: </strong><?php echo esc_html( $feat_Specials ) ?></p>
  <?php endif; ?>
</div>
